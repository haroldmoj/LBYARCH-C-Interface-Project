# LBYARCH Machine Project 2: x86-to-C Interface Programming
```By Mojica, Harold C. and Yung Cheng, Adrian U. of S15```

This project performs a 1-dimensional stencil of a vector `X` with size `n` and places the result in a vector `Y` both in x86-64 assembly and C language. The program runs each kernel 30 times for a more distinct yield in average runtime and utilizes array sizes of 2^29 elements but will only be additionally ran at sizes 2^20 and 2^24. A max size of 2^30 was tested for the program but produced inconsistent results (e.g. successful run but greatly varied average runtime, or does not run at all). 

## 1-D Stencil Formula

$Y[i] = X[i - 3] + X[i - 2] + X[i - 1] + X[i] + X[i + 1] + X[i + 2] + X[i + 3]$

## Comparative Analysis

### Debug Mode
| **Vector Size**   | **C**             | **Assembly**      | **Faster** | **%**     |
|:-----------------:|:-----------------:|:-----------------:|:----------:|:---------:|
| $2^{20}$          | (time)            | (time)            | Assembly   | (percent) |
| $2^{24}$          | (time)            | (time)            | Assembly   | (percent) |
| $2^{29}$          | (time)            | (time)            | Assembly   | (percent) |


(explanation why Assembly is faster in debug mode)

### Release Mode
| **Vector Size**   | **C**             | **Assembly**      | **Faster** | **%**     |
|:-----------------:|:-----------------:|:-----------------:|:----------:|:---------:|
| $2^{20}$          | (time)            | (time)            | C          | (percent) |
| $2^{24}$          | (time)            | (time)            | C          | (percent) |
| $2^{29}$          | (time)            | (time)            | C          | (percent) |

(explanation why C is faster in release mode)

## Program Output Screenshots

To ensure that both kernels are able to procure the correct results, error checking and validation was implemented. For this program, the results produced by the C implementation will be used as the basis for correctness. A counter was made to check how many disparities were present in the ASM implementation's results. The greater the number the counter has, the more errors that the latter had produced in its results, while having 0 or no errors indicates that both implementations were similar in results. 

### Debug Mode

#### $2^{20}$
<img></img>
#### $2^{24}$
<img></img>
#### $2^{29}$

### Release Mode

#### $2^{20}$
<img></img>
#### $2^{24}$
<img></img>
#### $2^{29}$
<img></img>