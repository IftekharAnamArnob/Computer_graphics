## Bresenham's line algorithm
$\textrm{\large 1.Slope(m)}$ = $\frac{\Delta \Large y}{\Delta \Large x}$

$\textrm{\large Decision parameter (P) = }$ $2* \Delta {\Large y} -\Delta \Large x \space;$ $\textrm{\large If m<1 }$

$\textrm{\large Decision parameter (P) = }$ $2* \Delta {\Large x} -\Delta \Large y \space;$ $\textrm{\large If m>=1 }$

| $\textrm{\large m<1}$  | $\textrm{\large m>=1}$ |
| -------- | ------- |
|  <table><thead><tr><th>$\textrm{\large if p<0}$ </th><th>$\textrm{\large if p>=0}$</th></tr></thead><tbody><tr><td>${\Large {x_{i+1} = x_i + 1}}$ <br>${\Large {y_{i+1} = y_i}}$<br>${{\Large p_{k+1} = p_k + }2 * \Delta {\Large y}}$</td><td>${\Large {x_{i+1} = x_i + 1}}$ <br>${\Large {y_{i+1} = y_i + 1}}$<br>${{\Large p_{k+1} = p_k + } 2 * \Delta {\Large y} - 2 * \Delta {\Large x}}$</td></tbody></table> | <table><thead><tr><th>$\textrm{\large if p<0}$</th><th>$\textrm{\large if p>=0}$</th></tr></thead><tbody><tr><td>${\Large{x_{i+1} = x_i}}$ <br>${\Large{y_{i+1} = y_i + 1}}$<br>${{\Large p_{k+1} = p_k + }2 * \Delta {\Large x}}$</td><td>${\Large{x_{i+1} = x_i + 1}}$ <br>${\Large{y_{i+1} = y_i + 1}}$<br>${{\Large p_{k+1} = p_k + 2 }* \Delta {\Large x} - \Delta {\Large y}}$</td></tbody></table>|



```

 
```

| | $\textrm{\large x}$ | $\textrm{\large y}$ | |
|---|---|---|---|
| |   1   |  1   | |
| |   2   |  1   | |
| |   3   |  2   | |
| |   4   |  2   | |
| |   5   |  3   | |
| |   6   |  3   | |
| |   7   |  4   | |
| |   8   |  4   | |

 ```math
\begin{aligned} 
 \textrm{\large Output for the Case 1: (1,1), (4,8)} \\

 \end{aligned} 
```
| | $\textrm{\large x}$ | $\textrm{\large y}$ | |
|---|---|---|---|
| |   1   |  1   | |
| |   1   |  2   | |
| |   2   |  3   | |
| |   2   |  4   | |
| |   3   |  5   | |
| |   3   |  6   | |
| |   4   |  7   | |
| |   4   |  8   | |







