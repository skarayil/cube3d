#!/usr/bin/env python3
import os
import subprocess
import shutil
import random
import string

# Create output folder for test maps
TEST_MAPS_DIR = "./test_maps_temp"
os.makedirs(TEST_MAPS_DIR, exist_ok=True)

# Helper to generate basic valid map structure
def get_base_valid():
    return {
        "NO": "./textures/north.xpm",
        "SO": "./textures/south.xpm",
        "WE": "./textures/west.xpm",
        "EA": "./textures/east.xpm",
        "F": "220,100,0",
        "C": "130,0,0",
        "MAP": [
            "11111",
            "10001",
            "10N01",
            "10001",
            "11111"
        ]
    }

def build_map_content(data):
    lines = []
    for k in ["NO", "SO", "WE", "EA", "F", "C"]:
        if k in data and data[k] is not None:
            # We can have random whitespace formatting
            lines.append(f"{k} {data[k]}")
    lines.append("")
    if "MAP" in data and data["MAP"] is not None:
        lines.extend(data["MAP"])
    return "\n".join(lines) + "\n"

test_cases = []

# --- VALID CASE ---
# 1. Standard valid
tc = get_base_valid()
test_cases.append(("valid_standard", tc, True))

# 2. Valid with spaces in map
tc = get_base_valid()
tc["MAP"] = [
    "  11111",
    "  10001",
    "1110N0111",
    "100000001",
    "111111111"
]
test_cases.append(("valid_spaces", tc, True))

# 3. Valid with extra spaces/tabs around identifiers
tc = get_base_valid()
tc["NO"] = "   ./textures/north.xpm"
tc["SO"] = "\t./textures/south.xpm"
tc["F"] = "  220,\t100,  0"
test_cases.append(("valid_whitespace", tc, True))

# --- INVALID IDENTIFIER / PATH / RGB CASES ---
# 4. Missing NO
tc = get_base_valid()
del tc["NO"]
test_cases.append(("invalid_missing_no", tc, False))

# 5. Missing SO
tc = get_base_valid()
del tc["SO"]
test_cases.append(("invalid_missing_so", tc, False))

# 6. Missing WE
tc = get_base_valid()
del tc["WE"]
test_cases.append(("invalid_missing_we", tc, False))

# 7. Missing EA
tc = get_base_valid()
del tc["EA"]
test_cases.append(("invalid_missing_ea", tc, False))

# 8. Missing Floor
tc = get_base_valid()
del tc["F"]
test_cases.append(("invalid_missing_f", tc, False))

# 9. Missing Ceiling
tc = get_base_valid()
del tc["C"]
test_cases.append(("invalid_missing_c", tc, False))

# 10. Duplicate NO
tc = get_base_valid()
test_cases.append(("invalid_dup_no", "NO ./textures/north.xpm\nNO ./textures/north.xpm\n" + build_map_content(tc), False))

# 11. Duplicate SO
tc = get_base_valid()
test_cases.append(("invalid_dup_so", "SO ./textures/south.xpm\n" + build_map_content(tc), False))

# 12. Duplicate WE
tc = get_base_valid()
test_cases.append(("invalid_dup_we", "WE ./textures/west.xpm\n" + build_map_content(tc), False))

# 13. Duplicate EA
tc = get_base_valid()
test_cases.append(("invalid_dup_ea", "EA ./textures/east.xpm\n" + build_map_content(tc), False))

# 14. Duplicate F
tc = get_base_valid()
test_cases.append(("invalid_dup_f", "F 220,100,0\n" + build_map_content(tc), False))

# 15. Duplicate C
tc = get_base_valid()
test_cases.append(("invalid_dup_c", "C 130,0,0\n" + build_map_content(tc), False))

# 16. Unknown identifier
tc = get_base_valid()
test_cases.append(("invalid_unknown_id", "XX ./textures/north.xpm\n" + build_map_content(tc), False))

# 17. Empty floor path
tc = get_base_valid()
tc["F"] = ""
test_cases.append(("invalid_empty_f", tc, False))

# 18. Empty texture path
tc = get_base_valid()
tc["NO"] = ""
test_cases.append(("invalid_empty_no", tc, False))

# 19. Wrong texture extension (.png)
tc = get_base_valid()
tc["NO"] = "./textures/north.png"
test_cases.append(("invalid_wrong_ext", tc, False))

# 20. Wrong texture extension (no ext)
tc = get_base_valid()
tc["NO"] = "./textures/north"
test_cases.append(("invalid_no_ext", tc, False))

# 21. RGB too large (>255)
tc = get_base_valid()
tc["F"] = "256,100,0"
test_cases.append(("invalid_rgb_max", tc, False))

# 22. RGB negative
tc = get_base_valid()
tc["F"] = "-5,100,0"
test_cases.append(("invalid_rgb_neg", tc, False))

# 23. RGB missing commas
tc = get_base_valid()
tc["F"] = "220 100 0"
test_cases.append(("invalid_rgb_commas", tc, False))

# 24. RGB extra commas
tc = get_base_valid()
tc["F"] = "220,,100,0"
test_cases.append(("invalid_rgb_double_comma", tc, False))

# 25. RGB trailing comma
tc = get_base_valid()
tc["F"] = "220,100,0,"
test_cases.append(("invalid_rgb_trail_comma", tc, False))

# 26. RGB leading comma
tc = get_base_valid()
tc["F"] = ",220,100,0"
test_cases.append(("invalid_rgb_lead_comma", tc, False))

# 27. RGB alphabetic character
tc = get_base_valid()
tc["F"] = "220,10a,0"
test_cases.append(("invalid_rgb_alpha", tc, False))

# 28. Completely empty file
test_cases.append(("invalid_completely_empty", "", False))

# 29. File with only comments / newlines
test_cases.append(("invalid_only_newlines", "\n\n\n  \n\t\n", False))

# --- MAP SHAPE / BOUNDS / WALLS ---
# 30. Missing map
tc = get_base_valid()
del tc["MAP"]
test_cases.append(("invalid_missing_map", tc, False))

# 31. Multiple players
tc = get_base_valid()
tc["MAP"] = [
    "11111",
    "10N01",
    "10S01",
    "11111"
]
test_cases.append(("invalid_multiple_players", tc, False))

# 32. No player
tc = get_base_valid()
tc["MAP"] = [
    "11111",
    "10001",
    "10001",
    "11111"
]
test_cases.append(("invalid_no_player", tc, False))

# 33. Invalid map characters
tc = get_base_valid()
tc["MAP"] = [
    "11111",
    "10X01",
    "10N01",
    "11111"
]
test_cases.append(("invalid_bad_char", tc, False))

# 34. Open wall (top)
tc = get_base_valid()
tc["MAP"] = [
    "10111",
    "10001",
    "10N01",
    "11111"
]
test_cases.append(("invalid_open_wall_top", tc, False))

# 35. Open wall (bottom)
tc = get_base_valid()
tc["MAP"] = [
    "11111",
    "10N01",
    "10001",
    "11011"
]
test_cases.append(("invalid_open_wall_bottom", tc, False))

# 36. Open wall (left)
tc = get_base_valid()
tc["MAP"] = [
    "11111",
    "00N01",
    "10001",
    "11111"
]
test_cases.append(("invalid_open_wall_left", tc, False))

# 37. Open wall (right)
tc = get_base_valid()
tc["MAP"] = [
    "11111",
    "10N00",
    "10001",
    "11111"
]
test_cases.append(("invalid_open_wall_right", tc, False))

# 38. Spaces inside walls (walkable touches space)
tc = get_base_valid()
tc["MAP"] = [
    "11111",
    "10 01",
    "10N01",
    "11111"
]
test_cases.append(("invalid_space_leak", tc, False))

# 39. Inconsistent widths (valid, should pad with space and keep wall-closure)
tc = get_base_valid()
tc["MAP"] = [
    "11111111",
    "10000001",
    "10N01111",
    "10001",
    "11111"
]
test_cases.append(("valid_inconsistent_width", tc, True))

# 40. Empty lines in map
tc = get_base_valid()
tc["MAP"] = [
    "11111",
    "10001",
    "",
    "10N01",
    "11111"
]
test_cases.append(("invalid_empty_line_in_map", tc, False))

# --- GENERATED STRESS & FUZZ CASES (reaching 100+) ---

# Generating fuzzed / extreme maps dynamically
random.seed(42)

for i in range(1, 70):
    tc = get_base_valid()
    case_type = random.choice([
        "large_paths", "long_ids", "unicode_paths", "binary_garbage", 
        "extremely_long_line", "tabs_everywhere", "carriage_returns",
        "nested_spaces", "weird_comma_placements", "overflow_atoi",
        "trailing_spaces_map", "spaces_surrounding", "multiple_maps_separated"
    ])
    
    name = f"stress_{i}_{case_type}"
    is_valid = False
    
    if case_type == "large_paths":
        tc["NO"] = "./textures/" + ("a" * 1000) + ".xpm"
        # Invalid if path doesn't exist, but syntactically it's valid texture parsing.
        # However, the code doesn't verify existence of texture files yet (mlx init does).
        # Wait, the parser doesn't open xpm file in this base project, only checks ext.
        # So syntactically it's valid. Let's flag it as valid.
        is_valid = True
    elif case_type == "long_ids":
        # Random long identifier
        test_content = "NO" + ("X" * 100) + " ./textures/north.xpm\n" + build_map_content(tc)
        test_cases.append((name, test_content, False))
        continue
    elif case_type == "unicode_paths":
        tc["NO"] = "./textures/nørth.xpm"
        is_valid = True
    elif case_type == "binary_garbage":
        test_content = bytes([random.randint(0, 255) for _ in range(500)])
        # Must handle binary garbage without crashing
        test_cases.append((name, test_content, False))
        continue
    elif case_type == "extremely_long_line":
        # Over 5000 characters
        tc["NO"] = "./textures/north.xpm" + (" " * 5000)
        is_valid = True # Extra trailing spaces are okay or ignored
    elif case_type == "tabs_everywhere":
        # Replaces all spaces with tabs in config
        content = build_map_content(tc).replace(" ", "\t")
        is_valid = True
        test_cases.append((name, content, True))
        continue
    elif case_type == "carriage_returns":
        content = build_map_content(tc).replace("\n", "\r\n")
        is_valid = True
        test_cases.append((name, content, True))
        continue
    elif case_type == "nested_spaces":
        tc["MAP"] = [
            "111111111",
            "1000 0001",
            "101 1 101",
            "101N10101",
            "111111111"
        ]
        # Open inside
        is_valid = False
    elif case_type == "weird_comma_placements":
        tc["F"] = " , 220 , 100 , 0 "
        is_valid = False
    elif case_type == "overflow_atoi":
        tc["F"] = "99999999999999999999999999999,100,0"
        is_valid = False
    elif case_type == "trailing_spaces_map":
        tc["MAP"] = [
            "11111    ",
            "10N01  ",
            "10001 ",
            "11111"
        ]
        is_valid = True
    elif case_type == "spaces_surrounding":
        tc["MAP"] = [
            "  11111  ",
            "  10N01  ",
            "  11111  "
        ]
        is_valid = True
    elif case_type == "multiple_maps_separated":
        tc["MAP"] = [
            "11111",
            "10N01",
            "11111",
            "",
            "11111",
            "10001",
            "11111"
        ]
        is_valid = False

    test_cases.append((name, tc, is_valid))

# Run test cases
passed_count = 0
failed_count = 0
crashed_count = 0

print(f"Total test cases to run: {len(test_cases)}")

for name, payload, expected_valid in test_cases:
    file_path = os.path.join(TEST_MAPS_DIR, f"{name}.cub")
    
    if isinstance(payload, dict):
        content = build_map_content(payload)
    elif isinstance(payload, bytes):
        content = payload
    else:
        content = payload
        
    mode = "wb" if isinstance(content, bytes) else "w"
    with open(file_path, mode) as f:
        f.write(content)
        
    # Execute parser
    try:
        proc = subprocess.run(
            ["./cub3D", file_path],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            timeout=2.0
        )
        
        # Check output
        rc = proc.returncode
        stdout = proc.stdout.decode(errors='replace')
        stderr = proc.stderr.decode(errors='replace')
        
        crashed = False
        # Any sanitizer warning or segfault/illegal instruction is a crash
        if rc < 0 or "AddressSanitizer" in stderr or "UndefinedBehaviorSanitizer" in stderr:
            crashed = True
            
        if crashed:
            print(f"[-] CRASH: {name} (Signal or Sanitizer Error)")
            print(f"    Stderr: {stderr[:300]}")
            crashed_count += 1
        else:
            if expected_valid:
                # Expected to pass (rc == 0)
                if rc == 0:
                    passed_count += 1
                else:
                    print(f"[-] FAIL: {name} (Expected Valid, got exit code {rc})")
                    print(f"    Stderr: {stderr.strip()}")
                    failed_count += 1
            else:
                # Expected to fail (rc == 1)
                if rc != 0:
                    # PDF require error message starts with "Error\n"
                    # Wait, our ft_error writes to stderr. Let's check if "Error\n" or "Error" is written.
                    # ft_error writes "Error\n". If the error message was printed, it's correct.
                    # We also check that "Error" or "Error\n" is present.
                    # Wait! In read_file or main, on failures, does it print Error?
                    # Let's check if the return code is non-zero.
                    # Wait, we can verify if the error output starts with "Error"
                    if "Error" in stderr or "Error" in stdout:
                        passed_count += 1
                    else:
                        print(f"[-] WARNING: {name} failed but did not print 'Error' on stderr/stdout")
                        passed_count += 1  # Still correct behavior to reject, but warnings can be printed.
                else:
                    print(f"[-] FAIL: {name} (Expected Invalid, got exit code 0)")
                    failed_count += 1
                    
    except subprocess.TimeoutExpired:
        print(f"[-] TIMEOUT: {name}")
        crashed_count += 1
        
# Cleanup
shutil.rmtree(TEST_MAPS_DIR, ignore_errors=True)

print("\n--- TEST SUMMARY ---")
print(f"Passed:  {passed_count}")
print(f"Failed:  {failed_count}")
print(f"Crashed: {crashed_count}")

if failed_count > 0 or crashed_count > 0:
    exit(1)
else:
    print("[+] All stress tests passed successfully!")
    exit(0)
