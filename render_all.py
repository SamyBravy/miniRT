import os
import subprocess

SCENE_DIR = "scenes"
EXECUTABLE = "./miniRT"

def render_all():
    if not os.path.exists(SCENE_DIR):
        print(f"Directory {SCENE_DIR} not found.")
        return

    # Filter for .rt files
import os
import subprocess

SCENE_DIR = "scenes"
EXECUTABLE = "./miniRT"

def render_all():
    if not os.path.exists(SCENE_DIR):
        print(f"Directory {SCENE_DIR} not found.")
        return

    # Filter for .rt files
    files = [f for f in os.listdir(SCENE_DIR) if f.endswith(".rt")]
    
    if not files:
        print("No .rt files found.")
        return

    RESULTS_DIR = "results"
    if not os.path.exists(RESULTS_DIR):
        os.makedirs(RESULTS_DIR)

    print(f"Found {len(files)} scenes. Starting render...")

    for i, file in enumerate(files):
        scene_path = os.path.join(SCENE_DIR, file)
        print(f"[{i+1}/{len(files)}] Rendering {file}...")
        
        try:
            # We assume the C program is compiled and --save works
            # Since this is WSL, we assume X server is available or not passed to headless if handled
            # But miniRT usually connects to X. 
            # If X is not available, mlx_init fails. 
            # Assuming the environment has X (since user screenshots worked).
            # Render (saves as scenes/file.rt.bmp)
            subprocess.run([EXECUTABLE, scene_path, "--save"], check=True)
            
            # Move to results
            generated_bmp = f"{scene_path}.bmp"
            target_bmp = os.path.join(RESULTS_DIR, f"{file}.bmp")
            
            if os.path.exists(generated_bmp):
                if os.path.exists(target_bmp):
                    os.remove(target_bmp)
                os.rename(generated_bmp, target_bmp)
                print(f"Saved to {target_bmp}")
            else:
                print(f"Warning: {generated_bmp} was not created.")
                
        except subprocess.CalledProcessError as e:
            print(f"Error rendering {file}: {e}")
            
    print(f"All renders complete. Check the '{RESULTS_DIR}' directory.")

if __name__ == "__main__":
    render_all()
