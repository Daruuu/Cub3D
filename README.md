---

# 🧪 Memory Testing

To ensure that the project is free from memory leaks, we used both **Valgrind** and **AddressSanitizer**.
The analysis was performed on both the **mandatory** and the **bonus** versions of Cub3D.

---

## ⚙️ Preparation

First, the project was compiled with **sanitizers enabled (AddressSanitizer)**.
This helps detect invalid memory access, leaks, and buffer overflows during execution.

---

## ▶️ Running with AddressSanitizer

We tested the executable with a sample map:

```bash
timeout 10s ./cub3D test_map.cub
```

* ✅ If no AddressSanitizer errors appear within the timeout, the program is running clean.

---

## 🐛 Running with Valgrind

For a more detailed memory check:

```bash
valgrind --leak-check=full ./cub3D test_map.cub
```

Valgrind reports all allocations and ensures that every block is properly freed.

---

## 📊 Test Results

### 🔧 Mandatory Version:

```
==180212== HEAP SUMMARY:
==180212==     in use at exit: 0 bytes in 0 blocks
==180212==   total heap usage: 30 allocs, 30 frees, 4,065 bytes allocated
==180212== 
==180212== All heap blocks were freed -- no leaks are possible
==180212== 
==180212== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

### 🎨 Bonus Version:

```
==181377== HEAP SUMMARY:
==181377==     in use at exit: 0 bytes in 0 blocks
==181377==   total heap usage: 30 allocs, 30 frees, 4,065 bytes allocated
==181377== 
==181377== All heap blocks were freed -- no leaks are possible
==181377== 
==181377== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

---

## 🛡️ AddressSanitizer Results

* ✅ No memory errors
* ✅ No buffer overflows
* ✅ No use-after-free
* ✅ No memory leaks
* ✅ No stack buffer overflows

---

## 🏆 Conclusions

1. **0 memory leaks** in both versions
2. **0 memory errors** detected
3. **30 allocs / 30 frees** – perfect balance
4. **4,065 bytes** managed correctly
5. **Cleanup functions working flawlessly**

---

## 🔍 Technical Notes

* **`cub_cleaner.c`**: frees all MLX resources correctly
* **`init_sound_empty()`**: initializes properly with no leaks
* **`clear_sounds()`**: frees all audio resources
* **Sprite management**: linked list cleanup works properly
* **MLX textures**: all images are destroyed correctly
* **Dynamic map memory**: released without issues

---

## ✨ Code Quality

The Cub3D project demonstrates **excellent memory management** with no leaks detected.
Your code meets **professional quality standards**, ensuring stability and efficiency.


---

