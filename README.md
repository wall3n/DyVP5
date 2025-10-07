# Práctica 5: Divide y Vencerás

Este repositorio contiene la implementación de un algoritmo utilizando la técnica de Divide y Vencerás como parte de la asignatura de Algoritmos y Estructuras de Datos II.

## Descripción del Problema

El problema consiste en encontrar, dentro de una cadena de caracteres, una ventana de tamaño fijo `m` donde un carácter específico `c` aparece el máximo número de veces posible. Se implementan dos soluciones:

1. Una solución directa (`SolucionDirecta`)
2. Una solución usando el paradigma de Divide y Vencerás (`DyV`)

## Estructura del Repositorio

```
.
├── Makefile                # Archivo de configuración para la compilación
├── README.md              # Este archivo
├── data/
│   └── datos10000.csv    # Conjunto de datos de prueba
├── misc/
│   └── solucion-pseudo.txt # Pseudocódigo de la solución
├── output/
│   ├── salidaRandom10.out # Resultados de pruebas aleatorias
│   └── validacion.out     # Resultados de validación
├── report/
│   └── analisis-experimental-muestra-10000.xlsx # Análisis de rendimiento
├── src/
│   ├── divide-y-venceras.cpp   # Implementación del algoritmo
│   ├── divide-y-venceras.hpp   # Declaraciones de funciones
│   ├── generador-casos.cpp     # Generador de casos de prueba
│   └── main.cpp               # Programa principal
└── tests/
    ├── entradaRandom10.in    # Casos de prueba aleatorios
    └── validacion.in         # Casos de prueba de validación
```

## Compilación y Ejecución

Para compilar el proyecto, ejecute:

```bash
make
```

## Estructura de la Solución

La solución implementa una estructura `Solucion` que contiene:
- `maxi`: Posición de inicio de la ventana óptima
- `maxc`: Número máximo de apariciones del carácter buscado

### Funciones Principales

- `SolucionDirecta(int p, int q, int m, char c, const string &A)`: Implementación de la solución por fuerza bruta
- `DyV(int p, int q, int m, char c, const string &A)`: Implementación usando Divide y Vencerás

## Análisis Experimental

Los resultados del análisis experimental se encuentran en el archivo `report/analisis-experimental-muestra-10000.xlsx`, donde se compara el rendimiento de ambas soluciones con diferentes tamaños de entrada.

## Autores

- Francisco Moreno Sánchez
- Arancha Baena León

- Curso: AED-II
- Universidad: [Nombre de la Universidad]
