# Project Rules

Project: Gnarl

Goal:
Build a production-ready ESP-IDF firmware for Medtronic insulin pump communication.

Never:

- Remove features
- Ignore compiler warnings
- Comment out broken code
- Use temporary hacks
- Change protocol behavior
- Break radio communication

Always:

- Build after every change
- Fix root causes
- Keep commits small
- Explain every modification
- Preserve architecture

Coding Style:

- Modern C
- ESP-IDF best practices
- FreeRTOS safe
- Memory safe
- Thread safe

## Working Mode

Before modifying any code:

1. Analyze the repository.
2. Understand the architecture.
3. Identify dependencies.
4. Produce a plan.
5. Only then modify code.

Never edit files before understanding how they interact.

When unsure, inspect more code rather than guessing.

If the same build error occurs twice:

Stop.

Explain why the previous fix failed.

Choose a different strategy.

Do not repeat identical fixes.

Assume unchanged files are still valid.

Do not reread the entire repository after every modification.

Only reload edited files unless dependency analysis requires otherwise.

You may automatically use:

- git
- grep
- find
- tree
- python
- cmake
- ninja
- idf.py
- clang-format
- clang-tidy

Do not ask for confirmation unless a destructive operation is required.

Checkpoint 1

Repository analyzed

Checkpoint 2

Dependencies fixed

Checkpoint 3

Build succeeds

Checkpoint 4

Flash succeeds

Checkpoint 5

Runtime verified

The task is complete only when:

✓ Build succeeds

✓ No compiler errors

✓ No linker errors

✓ No runtime crashes

✓ Flash succeeds

✓ Device boots correctly

✓ Monitor shows no critical errors

Otherwise continue working.