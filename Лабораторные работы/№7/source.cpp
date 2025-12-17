#include <Python.h>

static PyObject* zero_array(PyObject* self, PyObject* args) {
    int size;
    if (!PyArg_ParseTuple(args, "i", &size))
        return NULL;

    if (size < 0) {
        PyErr_SetString(PyExc_ValueError, "–азмер массива не может быть отрицательным");
        return NULL;
    }

    PyObject* listObj = PyList_New(size);
    for (int i = 0; i < size; i++) {
        PyList_SetItem(listObj, i, PyLong_FromLong(0));
    }
    return listObj;
}

static char zeroArray_docs[] =
"create(size): create zero-filled list\n";

static PyMethodDef zeroArray_funcs[] = {
    {"create", zero_array, METH_VARARGS, zeroArray_docs},  
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef zeroArray_module = {
    PyModuleDef_HEAD_INIT,
    "zeroArray",
    "Create zero-filled arrays",
    -1,
    zeroArray_funcs
};

extern "C" PyMODINIT_FUNC PyInit_zeroArray(void) {
    return PyModule_Create(&zeroArray_module);
}

