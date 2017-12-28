# Linux

## Intel power mode

默认的电源模式就是balanced

安装linux-tools后可以调节到powersave或者performance

```bash
sudo apt-get install linux-tools-common

sudo cpupower frequency-set -g powersave
sudo cpupower frequency-set -g performance
```

可以从apt list里看到支持的kernel版本，笔记本上的kernel由于太新，linux-tools没有跟上，因此还是无法调节。
