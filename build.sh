#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"
cd "$ROOT_DIR"

echo "Compilando logger..."
gcc -Wall -Wextra -std=c11 -g logger.c main.c -o main

if [ "${1-}" = "clean" ]; then
  echo "Limpiando artefactos..."
  rm -f main
  exit 0
fi

echo "Hecho. Ejecutable: main"