# Logger

Descripción
- Librería simple en C para logging (INFO, WARN, ERROR) a archivo con rotación automática.

Requisitos
- `gcc` (o `clang`), utilidades estándar de Unix.

Uso rápido
1. Abrir la carpeta del proyecto:

```bash
cd Logger
```

2. Compilar con el script `build.sh`:

```bash
./build.sh
```

3. Ejecutar el binario resultante:

```bash
./main
```

Opciones del `build.sh`
- `./build.sh clean` — limpia artefactos de compilación.

Notas
- Los logs se escriben en `logs/app.log` (rotación a 4KB).
- Para comprobar fugas de memoria usa `valgrind --leak-check=full ./main`.

Licencia
- MIT