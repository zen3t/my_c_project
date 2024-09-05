import os
import subprocess

def main():
    # Caminho para o código C
    project_dir = os.path.dirname(__file__)
    c_code_dir = os.path.join(project_dir, 'src', 'c_code')
    c_file = os.path.join(c_code_dir, 'main.c')
    output_file = os.path.join(c_code_dir, 'main')
    
    # Comando para compilar o código C
    compile_cmd = f"gcc {c_file} -o {output_file}"
    subprocess.run(compile_cmd, shell=True, check=True)
    
    # Executar o binário gerado
    # Usando o caminho absoluto do arquivo
    run_cmd = f"{output_file}"
    subprocess.run(run_cmd, shell=True, check=True)

if __name__ == "__main__":
    main()

