
CMake Library Project Template
===========
[![Build status](https://ci.appveyor.com/api/projects/status/irafbluexmulat6u/branch/main?svg=true)](https://ci.appveyor.com/project/jgonzalezdr/projecttemplatelib/branch/main)
[![codecov](https://codecov.io/gh/jgonzalezdr/ProjectTemplateLib/branch/main/graph/badge.svg)](https://codecov.io/gh/jgonzalezdr/ProjectTemplateLib)
## About

This repository is just a template for a library built using [CMake](https://cmake.org/), and using [cpputest](http://cpputest.github.io/) for unit test execution.

## Usage

1.  Download all the [files from this repository as a ZIP file](https://github.com/jgonzalezdr/projecttemplatelib/archive/main.zip) and unzip them to your project base directory.

> The _main_ branch is populated with some example files. You may download a [version without any examples](https://github.com/jgonzalezdr/projecttemplatelib/archive/unpopulated.zip) from the _unpopulated_ branch.

2. Edit the top level `CMakefile.txt` and replace _ProjectTemplate_ in the project command with your own project name (leave the .Top suffix).

3. Put the headers for your public functions and classes in `lib/include/`.

4. Put the headers for your private functions and classes and the implementation files in `lib/sources/`.

5. Edit `lib/CMakefile.txt` and replace _ProjectTemplate_ in the project command with your own project name (this time without the ".Top" suffix, and also don't use any "lib" prefix or suffix in the project name). This will be the base name for the library file. You may also update your project version in the project command.

6. Edit `lib/CMakefile.txt` and set the list of source and header files, and modify any other parameters that you like.

7. Add your common mocks and expectation functions to `test/Mocks`. 

8. To create unit tests, copy the `test/TestTemplate/` directory to another directory under `test/` renaming it with the test name, then:
   - Rename the test implementation file `TestModule_test.cpp` according to your test module name (It's recommended to leave the _ _test_ suffix).
   - Edit the test's `CMakefile.txt`:
       - Replace _ProjectTemplate_ and _TestModule_ in the project command with your own project name and test module name (e.g. "_YourProjectName_.Test._YourTestModuleName_").
       - Set the list of production source files to be tested, and the list of test source files (test, mocks, other test helper functions, etc.).
   - Edit the test implementation file to add your tests.

9. Edit `test/CMakefile.txt` and add all the subdirectories for your tests.

10. To create example applications that use the library, copy the `examples/ExampleTemplate/` directory to another directory under `examples/` renaming it with the example name, then:
   - Rename the example implementation file `ExampleTemplate.cpp` according to your example's name.
   - Edit the examples's `CMakefile.txt`:
       - Replace _ProjectTemplate_ and _ExampleTemplate_ in the project command with your own project name and example name (e.g. "_YourProjectName_.Test._YourExampleName_").
       - Set the list of source files for the example.
   - Edit the example implementation file to add your tests.

11. Edit `examples/CMakefile.txt` and add all the subdirectories for your examples.

13. Replace `LICENSE.txt` with your project's license file.

14. Create a build directory under the top directory (e.g. `build/`), and inside it execute `cmake .. G "<GeneratorOfYourChoice>"` (add any other configuration options that you like).

## CMake Project Options

| OPTION                | Description |
| -                     | - |
| `-DCMAKE_BUILD_TYPE`  | Selects build type<br>_(only for single-config generators)_<br>`Debug`<br>`Release`_(default)_<br>`RelWithDebInfo` (Release with debug info)<br>`MinSizeRel`(Release with size optimization)<br> `Coverage`(Debug with code coverage enabled) |
| `-DBUILD_SHARED_LIB`  | Enables generation of shared library<br>`ON`_(default)_<br>`OFF` |
| `-DBUILD_STATIC_LIB`  | Enables generation of static library<br>`ON`_(default)_<br>`OFF` |
| `-DENABLE_TEST`       | Enables compilation and execution of tests<br>`ON`_(default)_<br>`OFF` |
| `-DCPPUTEST_HOME`     | Path to your CppUTest installation directory<br>`<filesystem path>` |
| `-DLCOV_HOME`         | Path to your LCOV installation directory<br>`<filesystem path>` |
| `-DENABLE_INSTALLER`  | Enables generation of installer packages<br>`ON`_(default)_<br>`OFF` |
| `-DBUILD_EXAMPLES`    | Enables building examples<br>`ON`_(default)_<br>`OFF` |
| `-DCOVERAGE`          | Enables code coverage in tests<br>_(only for multi-config generators)_<br>`ON`_(default)_<br>`OFF` |
| `-DCOVERAGE_VERBOSE`  | Enables verbose code coverage<br>`ON`<br>`OFF`_(default)_ |
| `-DCI_MODE`           | Enables Continous Integration mode<br>`ON`<br>`OFF`_(default)_ |

## Requirements

- [cmake](https://cmake.org/) (tested with v3.7.1 and 3.17.2)
- [CppUTest](http://cpputest.github.io/) [Optional, not needed if tests are disabled] (tested with v3.7.1, v3.7.2, v3.8 and [v3.9.alpha0](https://github.com/jgonzalezdr/cpputest/releases/download/v3.9.alpha0/cpputest-3.9.alpha0.zip))
- On Windows:
  - A C/C++ compiler, either:
    - [MinGW-w64](https://sourceforge.net/projects/mingw-w64/) (tested with v7.3.0, v8.1.0 and [TDM-GCC v9.2.0](https://jmeubank.github.io/tdm-gcc/download/))
    - [Microsoft Visual Studio](https://www.visualstudio.com/es/downloads/) (tested with Visual Studio Community 2019)
  - [LCOV for Windows](https://github.com/jgonzalezdr/lcov/releases) [Optional, needed if tests and coverage are enabled using MinGW] (tested with [v1.15.alpha1w](https://github.com/jgonzalezdr/lcov/releases/download/v1.15.alpha1w/lcov-v1.15.alpha1w.zip))
  - [OpenCppCoverage](https://github.com/OpenCppCoverage/OpenCppCoverage) [Optional, needed if tests and coverage are enabled using Visual Studio 2019] (tested with v0.9.8.0)
- On Linux:
  - [GCC](https://gcc.gnu.org/) (tested with v7.5.0, v8.4.0 and v9.3.0)
  - [LCOV](http://ltp.sourceforge.net/coverage/lcov.php) [Optional, needed if tests and coverage are enabled using GCC] (tested with v1.14)
