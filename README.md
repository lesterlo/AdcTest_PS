# AdcTest_PS




# Run the Patch

This patch will fix `-lopenamp No such file` error when building a Application with open-amp support. The reason for that is the static library of openamp is `libopen-amp.a` rather than `libopenamp.a`

```bash
# Run it in the root of your workspace

# For r5 core 0
ln ./platform/psu_cortexr5_0/freertos_psu_cortexr5_0/bsp/lib/libopen_amp.a ./platform/psu_cortexr5_0/freertos_psu_cortexr5_0/bsp/lib/libopenamp.a

# For r5 core 1
ln ./platform/psu_cortexr5_1/freertos_psu_cortexr5_1/bsp/lib/libopen_amp.a ./platform/psu_cortexr5_1/freertos_psu_cortexr5_1/bsp/lib/libopenamp.a
```