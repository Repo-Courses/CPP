int sqrRunTime(int n) { return n * n; }

consteval sqrCompileTime(int n) { return n * n; }

constexpr sqrRunOrCompileTime(int n) { return n * n; }

int main() {
    constexpr int p1 = sqrRunTime(100); // ERROR: not constexpr
    
    constexpr int p2 = sqrCompileTime(100);
    
    constexpr int p3 = sqrRunOrCompileTime(100);
    
    int x{100};
    
    int p4 = sqrRunTime(x);
    
    int p5 = sqrCompileTime(x); // ERROR: x not constant expression
    
    int p6 = sqrRunOrCompileTime(x);
    
    int p7 = sqrCompileTime(100); // compile-time

    int p8 = sqrRunOrCompileTime(100); // run-time or compile-time
}
