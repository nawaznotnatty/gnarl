# GNARL — build & development notes

GNARL ("GNARL is Not A RileyLink") is ESP32 firmware that emulates a RileyLink
so Loop / AndroidAPS can talk to Medtronic insulin pumps over BLE. Target board:
TTGO v1 ESP32 868/915 MHz LoRa OLED (RFM95 radio, SSD1306 OLED).

## Repository layout

- `src/<project>/`   — one subdirectory per application (`gnarl` is the default). Each holds its own `sdkconfig` and a `dependencies` file listing libs to pull from `lib/`.
- `lib/`             — shared components (medtronic, radio, oled, u8g2 submodule, wifi/tether, …).
- `include/`         — shared headers plus gitignored config headers (`pump_config.h`, `network_config.h`, …).
- `mk/`              — build scaffolding. `make-project.sh` assembles `project/` from a chosen `src/<project>`.
- `project/`         — GENERATED, gitignored. Do not edit directly; edit `src/<project>` and re-run `make <project>`.

## Build workflow

The top-level `Makefile` generates the ESP-IDF `project/` tree, then you build
inside it with `idf.py`:

```
make gnarl          # assemble project/ from src/gnarl  (also: make blink, make mmtune, …)
cd project
idf.py build
idf.py -p <PORT> flash monitor
```

`make <project>` copies `src/<project>` → `project/main`, moves its `sdkconfig`
up to `project/`, and pulls each lib named in `src/<project>/dependencies` into
`project/components`. It wipes `project/build`, so a rebuild after `make` is a
clean build.

> The source of truth for a project's `sdkconfig` is `src/<project>/sdkconfig`.
> Changes made in `project/sdkconfig` (e.g. via `idf.py menuconfig`) must be
> copied back there or they are lost on the next `make`.

## Windows / ESP-IDF gotchas (important)

This machine runs Claude Code under **git-bash (MSYS/MINGW64)**, but ESP-IDF's
tooling **refuses to run under MSYS** ("MSys/Mingw is not supported"). Builds
must go through the native Windows `cmd.exe`:

1. ESP-IDF v5.5.4 is installed at `C:\Espressif\frameworks\esp-idf-v5.5.4`
   (installed via the ESP-IDF Installation Manager / "eim").
2. The Python venv is **py3.11** (`C:\Espressif\python_env\idf5.5_py3.11_env`).
   `export.sh`/`export.bat` will otherwise auto-pick the system Python 3.13 and fail.
3. `export.bat` aborts if `MSYSTEM` is set, so clear it before calling.

A working wrapper (invoke from git-bash):

```bash
env -u MSYSTEM -u SHELL -u MSYS -u MINGW_PREFIX cmd.exe //c "C:\\path\\to\\idf-wrapper.bat build"
```

where `idf-wrapper.bat` is:

```bat
@echo off
set MSYSTEM=
set SHELL=
set IDF_PATH=C:\Espressif\frameworks\esp-idf-v5.5.4
set IDF_TOOLS_PATH=C:\Espressif
call C:\Espressif\frameworks\esp-idf-v5.5.4\export.bat >nul 2>&1
cd /d C:\Users\nawaznotnatty\gnarl-1\project
idf.py %*
```

`make gnarl` itself (the shell script) DOES run fine under git-bash — only
`idf.py` needs cmd.exe.

## Device

The TTGO board enumerates as **COM5** ("USB-Enhanced-SERIAL CH9102"). Flash/monitor with:

```
idf.py -p COM5 flash monitor
```

## Board configuration

Pin map and OLED enable live in `include/module.h`. Uncomment `#define OLED_ENABLE`
to build for the OLED variant. Pump serial/frequency go in `include/pump_config.h`
(gitignored). See `README.md` for network/nightscout/papertrail config headers.
