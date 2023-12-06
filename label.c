#include "label.h"

static int label_cnt = 0;

int label_create(){
    return label_cnt++;
}

const char *label_name(int label){
    static char buffer[256];
    snprintf(buffer, 256, ".L%d", label);
    return strdup(buffer);
}
