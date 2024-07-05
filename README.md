# CutOff - VST3

This is an example of a vst3 plugin made using CMake and JUCE. The first VST3 version of Linux is available.

<p align="center">
<img src="https://github.com/filipeborato/cutoff-filter/assets/21025394/47e6dbac-fa04-4dd0-a32d-5b15430fecda" width=50% height=50%>
</p>

## Usage

This is a template repository which means you can right click "Use this template" on GitHub and create your own repo out of it.

After cloning it locally, you can proceed with the usual CMake workflow.

In the main repo directory execute

```bash
$ cmake -S . -B build
$ cmake --build build
```

The first run will take the most time because the dependencies (CPM, JUCE, and googletest) need to be downloaded.

Alternatively, you can use bundled CMake presets:

```bash
$ cmake --preset default # uses the Ninja build system
$ cmake --build build
$ ctest --preset default
```

Existing presets are `default`, `release`, and `Xcode`.

To run clang-format on every commit, in the main directory execute

```bash
pre-commit install
```

(for this you may need to install `pre-commit` with `pip`: `pip install pre-commit`).

Don't forget to change "YourPluginName" to, well, your plugin name everywhere 😉

