# WebAssembly Coalescence of Drops

Finite-volume simulation of two fluids with different densities.

[Online demo](https://cselab.github.io/aphros/wasm/hydro.html)

## Install

Uses
[emscripten](https://emscripten.org/docs/getting_started/downloads.html#sdk-download-and-install),
commands `emcc` and `emar` should be available. Build and open in a
web browser:

```
make
emrun --serve_after_exit hydro.html
```
