# LBYARCH Machine Project 2: x86-to-C Interface Programming
```Mojica, Harold C. | Yung Cheng, Adrian U. | S15```

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


From the average runtimes in debug mode, it can be inferred that the Assembly implementation has a better performance than the C implementation due to the consistency in difference of the average runtimes of each kernel at their respective array sizes. This can be due to the lower-level nature of the Assembly language plus its capacity to run multiple data operations using a single instruction being able to run and compute more optimally than that of the C implementation. 

### Release Mode
| **Vector Size**   | **C**             | **Assembly**      | **Faster** | **%**     |
|:-----------------:|:-----------------:|:-----------------:|:----------:|:---------:|
| $2^{20}$          | (time)            | (time)            | C          | (percent) |
| $2^{24}$          | (time)            | (time)            | C          | (percent) |
| $2^{29}$          | (time)            | (time)            | C          | (percent) |

In release mode, on the other hand, the C implementation possesses better processing speeds than that of the Assembly implementation. This can be attributed to the optimization abstraction techniques that comes along with a higher-level language that the former has compared to those available to the latter. Although on a considerably small scale due to the unit of measurement used, the difference in processing speeds can easily show that the C implementation does have its advantages and higher-level superiority in certain circumstances. 

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