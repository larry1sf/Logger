# Logger

Este proyecto implementa un sistema de logging simple en C. Permite registrar mensajes con diferentes niveles de severidad (INFO, WARNING, ERROR, DEBUG) en un archivo de log. Incluye rotación automática del archivo cuando supera los 4KB.

## Estructura del Proyecto

- `logger.h`: Definiciones y prototipos de funciones.
- `logger.c`: Implementación del logger.
- `main.c`: Ejemplo de uso del logger.
- `logs/`: Directorio para los archivos de log.

## Compilación

Ejecuta el script `build.sh` para compilar el proyecto:

```bash
./build.sh
```

Esto generará el ejecutable `main`.

## Uso

Después de compilar, ejecuta:

```bash
./main
```

El programa registrará varios mensajes de log en `logs/app.log`.

## Funcionalidades

- Inicialización del log con `log_init()`.
- Registro de mensajes con `log_message()`.
- Cierre del log con `log_close()`.
- Rotación automática del archivo de log.