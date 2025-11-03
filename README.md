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
