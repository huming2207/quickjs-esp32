# QuickJS Port for Espressif ESP32

Just a quick and dirty port for QuickJS on ESP32

## Known issue

- Memory management
    - `malloc_usable_size()` is not available for ESP32, so in `js_def_malloc_usable_size` it returns 0.
    - Maybe should try `heap_caps_get_allocated_size()` instead?
    
- Timezone 
    - ESP32 does not have full timezone support
    - So in `getTimezoneOffset()` of `quickjs.c` it always return 0 for now
    
- Some other warnings haven't been fixed

## License

MIT

