extern PyTypeObject SpriteType;

typedef struct {
    PyObject_HEAD
    float *center_x;
    float *center_y;
    float *change_x;
    float *change_y;
    float *width;
    float *height;
} SpriteObject;
