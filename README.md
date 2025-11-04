# lkm-reliant

Two Linux Kernel Modules. One of which exports symbols, which are then used by another. Inspired by [Rishi Agrawal's EXPORT_SYMBOL Tutorial](https://lkw.readthedocs.io/en/latest/doc/04_exporting_symbols.html).

## Exported & Imported Symbols

- `provider.c` exports `MY_NAME` and `trivial_sub`
- `user.c` imports `MY_NAME` and `trivial_sub` (alongside `_printk` & `__fentry__`)

## Development

### Building

```console
make
```

### Loading

```console
sudo insmod provider.ko
sudo insmod user.ko
```

### Unloading

```console
sudo rmmod user.ko
sudo rmmod provider.ko
```

### `clangd`

When using an LSP in Vim, it is possible to generate useful compile information.

#### Compile Commands JSON

This can be generated from the kernel source itself (it can be very large) or by using [Bear](https://github.com/rizsotto/Bear).

```console
make clean
bear -- make
```

#### Ignore `gcc` parameters

`clangd`, by defaults, warns at the use of `gcc`-specific parameters. For the sake of the LSP, we can ignore these problems, using the following `.clangd` file (taken from [this comment](https://github.com/clangd/clangd/issues/662#issuecomment-1447233948)).

```clangd
CompileFlags:
  Add: -Wno-unknown-warning-option
  Remove: [-m*, -f*]
```
