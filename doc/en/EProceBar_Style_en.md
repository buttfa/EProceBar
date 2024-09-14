### <div align="center">|[简体中文](../cn/EProceBar_Style.md)|[English](EProceBar_Style_en.md)|</div>

## <div align="center">Directory</div>
- [EProceBar preset style](#eprocebar-preset-style)
  - [1.Transmit Progress Bar](#1-transmit-progress-bar)
  - [2.Task Progress Bar](#2-task-progress-bar)
  - [3.Common Progress Bar](#3-common-progress-bar)
- [EPRoceBar Custom Style](#eprocebar-custom-style)

## EPRoceBar preset style
#### 1. Transmit progress bar
#### [Example of using the transmit progress bar](../../test/transmit_procebar_test.c)
#### 2. Task progress bar
#### [Example of using task progress bar](../../test/task_procebar_test.c)
#### 3. common progress bar
#### ① The common progress bar has high scalability and allow customization of styles to a certain extent. Here is an [example](../../test/common_procebar_test.c).
#### ② In addition to modifying the style parameters to change the style of the progress bar, the common progress bar can also be modified by constantly changing the content of the prefix and suffix to achieve the modification of the progress bar format<br> Here is an [example](../../test/common_transmit_test.c) to indirectly implement the transmit of progress bars using a common progress bar.


## EProceBar custom style
#### 1.  Create a progress bar parameter structure (not necessary, only defined when certain parameters are needed in your custom style).
#### Here is an example of the color_procebar progress bar parameter structure.
```c
/**
 * @brief Color Progress Bar Parameter Structure
 * 
*/
typedef struct {
    int* current_num;
    int* target_num;
    int length;
} color_procebar_arg;
```
#### 2.  Create a progress bar style macro definition.
#### Here is an example of the color_procebar style structure. Due to space limitations, the specific implementation of member functions in the style structure cannot be provided here. For details, please refer to [color_procebar.c](../../eprocebar/procebar_style/color_procebar.c).
```c
/**
 * @brief Color Progress Bar Default Length
 * 
 */
#define COLOR_PROCEBAR_LENGTH 20

/**
 * @brief Color Progress Bar Style Macro Definition
 * 
 */
#define COLOR_PROCEBAR (procebar_style){\
    .length = COLOR_PROCEBAR_LENGTH, \
    .print = color_procebar_print, \
    .start = color_procebar_start, \
    .end = color_procebar_end, \
    .get_prefix = color_procebar_prefix, \
    .get_suffix = color_procebar_suffix, \
    .get_full_char = color_procebar_full_char, \
    .get_empty_char = color_procebar_empty_char, \
}
```
#### If you want to customize the style of the progress bar, it is recommended to refer to the color_procebar progress bar example (including [source file](../../eprocebar/procebar_style/color_procebar.c) and [header file](../../eprocebar/procebar_style/color_procebar.h)), which implements a color progress bar that changes over time and is very helpful for a deeper understanding of how to customize progress bar styles.