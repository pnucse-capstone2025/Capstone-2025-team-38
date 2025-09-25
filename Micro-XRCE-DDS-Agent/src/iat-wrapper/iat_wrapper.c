#include <Python.h>
#include <iat/iat_wrapper.h>
#include <stdio.h>
#include <stdlib.h>

int run_check_iat(int argc, char *argv[]) {
    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;
    int i;
    wchar_t **argv_w = (wchar_t **)calloc(argc, sizeof(wchar_t *));
    if (!argv_w) {
        fprintf(stderr, "Memory allocation failed for argv_w\n");
        return 1;
    }

    Py_Initialize();

    // Add script directory to Python path
    PyObject* sysPath = PySys_GetObject("path");
    // NOTE: This assumes the C executable is run from the root of the tf-m-tools directory.
    // A more robust solution might get this path from an environment variable or build configuration.
    // PyObject* scriptPath = PyUnicode_FromString("build/micro_ros_agent/agent/src/xrceagent/src/iat-verifier/scripts");
    PyObject* scriptPath = PyUnicode_FromString("iat-verifier/scripts");
    PyList_Append(sysPath, scriptPath);
    Py_DECREF(scriptPath);
    
    pName = PyUnicode_DecodeFSDefault("check_iat");
    /* Error checking of pName left out */

    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, "main");
        /* pFunc is a new reference */

        if (pFunc && PyCallable_Check(pFunc)) {
            // Convert char * argv[] to wchar_t * argv_w[] for PySys_SetArgv
            for (i = 0; i < argc; i++) {
                argv_w[i] = Py_DecodeLocale(argv[i], NULL);
                if (!argv_w[i]) {
                    fprintf(stderr, "Fatal error: cannot decode argv[%d]\n", i);
                    for (int j = 0; j < i; j++) {
                        PyMem_RawFree(argv_w[j]);
                    }
                    free(argv_w);
                    Py_FinalizeEx();
                    return 1;
                }
            }
            PySys_SetArgv(argc, argv_w);

            // The Python 'main' function in check_iat doesn't expect arguments directly.
            // It uses argparse to parse them from sys.argv, which we've just set.
            pValue = PyObject_CallObject(pFunc, NULL);

            long result = -1; // Default to error
            if (pValue != NULL) {
                // The python script doesn't really return a useful value from main,
                // but we can check for exceptions.
                if (PyLong_Check(pValue)) {
                    result = PyLong_AsLong(pValue);
                    // printf("Result: %ld\n", result);
                }
                Py_DECREF(pValue);
            }
            else {
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
                Py_DECREF(pFunc);
                Py_DECREF(pModule);

                for (i = 0; i < argc; i++) {
                    PyMem_RawFree(argv_w[i]);
                }
                free(argv_w);

                Py_FinalizeEx();
                return 1;
            }

            // Clean up Python objects and argv_w before returning.
            Py_DECREF(pFunc);
            Py_DECREF(pModule);
            for (i = 0; i < argc; i++) {
                PyMem_RawFree(argv_w[i]);
            }
            free(argv_w);

            if (Py_FinalizeEx() < 0) {
                return 120;
            }

            return result;
        }
        else {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function \"main\"\n");
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"check_iat\"\n");
        free(argv_w);
        return 1;
    }

    for (i = 0; i < argc; i++) {
        PyMem_RawFree(argv_w[i]);
    }
    free(argv_w);


    if (Py_FinalizeEx() < 0) {
        return 120;
    }
    return 0;
}
