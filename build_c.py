import os
import subprocess
import sys

def main():
    # Verifica se o nome do arquivo foi passado como argumento
    if len(sys.argv) < 2:
        print("Uso: poetry run build_c <arquivo.c>")
        sys.exit(1)

    # Nome do arquivo .c passado como argumento
    c_file = sys.argv[1]

    # Verifica se o arquivo existe
    c_code_dir = os.getcwd()
    c_file_path = os.path.join(c_code_dir, c_file)
    
    if not os.path.exists(c_file_path):
        print(f"Arquivo {c_file} não encontrado.")
        sys.exit(1)

    # Nome do arquivo de saída sem a extensão .c
    output_file = os.path.splitext(c_file)[0]

    # Comando de compilação
    compile_cmd = f"gcc {c_file_path} -o {output_file}"

    print(f"Compilando {c_file}...")
    
    try:
        # Executa o comando de compilação
        subprocess.run(compile_cmd, shell=True, check=True)

        # Executa o programa compilado
        run_cmd = f"./{output_file}"
        subprocess.run(run_cmd, shell=True, check=True)
    except subprocess.CalledProcessError as e:
        print(f"Erro ao compilar/executar {c_file}: {e}")

if __name__ == "__main__":
    main()

