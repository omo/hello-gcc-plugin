
struct foo {
    int bar;
    int baz;

    void hello(int x, int y) {}
    void bye(char* x, char* y);
};

union u {
    int x;
    char* y;
};

enum e {
    A,
    B
};

template<class T>
struct templ
{
    T* x;
};

void foo::bye(char* x, char* y)
{
}

typedef int typedefed_int_t;

int main()
{
    return 0;
}
