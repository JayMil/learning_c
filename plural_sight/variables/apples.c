// must be static or will collide with oranges global variable
static int data;

void apples_set(int value) {
    data = value;
}

int apples_get() {
    return data;
}

