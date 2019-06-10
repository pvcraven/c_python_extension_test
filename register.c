#include <Python.h>
#include <structmember.h>
#include "sprite_list.h"
#include "sprite.h"

/**
 * Specify the module the Sprite class is in
 */
static PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "arcade.native",
    NULL,
    -1,
    NULL
};

/**
 * Main method to register Sprite
 */
PyMODINIT_FUNC
PyInit_native(void)
{
    if (PyType_Ready(&SpriteListType) < 0)
        return NULL;
    if (PyType_Ready(&SpriteType) < 0)
        return NULL;

    PyObject *m = NULL;
    if ((m = PyModule_Create(&module)) == NULL)
        return NULL;

    Py_XINCREF(&SpriteListType);
    Py_XINCREF(&SpriteType);

    PyModule_AddObject(m, "SpriteList", (PyObject *) &SpriteListType);
    PyModule_AddObject(m, "Sprite", (PyObject *) &SpriteType);

    return m;
}
