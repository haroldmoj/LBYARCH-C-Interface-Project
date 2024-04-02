# LBYARCH Machine Project 2: x86-to-C Interface Programming

This project performs a 1-dimensional stencil of a vector **X** with size **n** and places the result in a vector **Y** both in x86-64 assembly and C language. 

## Comparative Analysis

### Debug Mode
| **Vector Size**   | **C**             | **Assembly**      | **Faster** | **%**     |
|:-----------------:|:-----------------:|:-----------------:|:----------:|:---------:|
| $2^{20}$          | (time)            | (time)            | (C/ASM)    | (percent) |
| $2^{24}$          | (time)            | (time)            | (C/ASM)    | (percent) |
| $2^{29}$          | (time)            | (time)            | (C/ASM)    | (percent) |


(explanation why C/ASM is faster in debug mode)

### Release Mode
| **Vector Size**   | **C**             | **Assembly**      | **Faster** | **%**     |
|:-----------------:|:-----------------:|:-----------------:|:----------:|:---------:|
| $2^{20}$          | (time)            | (time)            | (C/ASM)    | (percent) |
| $2^{24}$          | (time)            | (time)            | (C/ASM)    | (percent) |
| $2^{29}$          | (time)            | (time)            | (C/ASM)    | (percent) |

(explanation why C/ASM is faster in release mode)

## Program Output Screenshots

To ensure that both kernels are able to procure the correct results, error checking and validation was implemented. As long as both kernels are able to produce the correct result at each iteration, (explanation and discussion).

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


## Group Members
1. Mojica, Harold C.
2. Yung Cheng, Adrian U.