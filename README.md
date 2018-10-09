Name: Hrishee Shastri
Calculating pi using the Griddle Pie Method. 
README

Question 1 Output:

    cout << gridpi(10);     // Output 3.52
    cout << gridpi(100);    // Output 3.1812
    cout << gridpi(1000);   // Output 3.14554
    cout << gridpi(10000);  // Output 3.14199



Question 2 Complexity and timing:

    Complexity analysis: gridpi is O(n^2) where n = npoints. 
    This is because the inner for-loop runs n times from i = 0 to i = n, 
    which in turn runs n times from j = 0 to j = n -- the total number of iterations is n*n. 
    
    Runtime for gridpi(10):     0m0.009s
    Runtime for gridpi(100):    0m0.012s
    Runtime for gridpi(1000):   0m0.293s
    Runtime for gridpi(10000):  0m27.949s



Question 3 timing with constexpr gridpi2:

                        Output-------------Runtime
    gridpi2(10):        3.52               0m0.010s           
    gridpi2(100):       3.1812             0m0.008s
    gridpi2(1000):      3.14554            0m0.009s

    The actual estimates of pi haven't changed, which is expected-- the computation to obtain it hasn't changed.
    The runtime for all gridpi2 inputs hovers around 0.009 seconds, which is a significant improvement to the increasing runtime of gridpi. This is probably because the constexpr allows the compiler to evaluate the output at compile time, so the executable .out file just spits out the result without needing to do any computation.

    However, I noticed that the compile time is significantly longer when constexpr is used. This is probably due to the added difficulty of trying to run something while compiling.

