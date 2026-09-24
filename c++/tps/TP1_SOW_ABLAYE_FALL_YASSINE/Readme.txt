# TP1 C++ — Switch, Overloading et Héritage

TP de C++ n°1 — Institut Galilée, Sup Galilée
Cours de R. KERVARC — M. LIENHARDT & L. POINSOT

## Contexte

Vous incarnez Zagreus, fils d'Hadès. Un ancien employé de Google, victime d'un
accident de travail causé par sa propre IA, vous révèle que les outils Google
ont été piratés. Votre mission : réimplémenter ces outils vous-même — de
plusieurs façons différentes, pour plus de sûreté.

Ce TP couvre : les enums typées (`enum class`), la surcharge d'opérateurs,
l'héritage et les classes abstraites, la gestion mémoire (fuites, `valgrind`),
et les quatre "états" d'une donnée en C++ (`T`, `T*`, `T&`, `T&&`).

## Structure du projet

```
src/
├── enum.hpp / enum.cpp                 # Exercice 1.A — conversions via enum
├── inheritance.hpp / inheritance.cpp   # Exercice 1.B — conversions via héritage
├── memory_1.cpp                        # Exercice 2.A.1 — main avec fuites
├── memory_2.cpp                        # Exercice 2.A.3 — correction (destructeur + copie supprimée)
├── memory_3.cpp                        # Exercice 2.A.4 — ajout d'un assert sur nullptr
├── data_1.hpp / data_1.cpp             # Exercice 2.B.1 — surcharge int / int* / int& / int&&
└── data_2.hpp / data_2.cpp             # Exercice 2.B.2 — résolution avec int const&&
```

## Exercice 1 — Les conversions de distance

### Partie A — Approche par énumération (`src/enum.hpp`, `src/enum.cpp`)

- `enum class distance_t { meters, feet, leagues, nautic_miles }` avec son
  opérateur `<<`.
- Classe `Distance` (champs `_value: double` et `_unit: distance_t`, tous deux
  `const`), avec constructeur et destructeur qui logguent leur passage, un
  opérateur `<<`, une méthode `convert_to(distance_t) const`, et les
  opérateurs de comparaison (`==`, `!=`, `<`, `<=`, `>`, `>=`).

Table de conversion utilisée :

| De → Vers | Facteur |
|---|---|
| mètre → pied | 3.280839895 |
| mètre → lieue | 0.0002071237 |
| mètre → mille marin | 0.0005399568 |
| pied → lieue | 6.31313e-5 |
| pied → mille marin | 0.0001645788 |
| lieue → mille marin | 2.606928726 |

### Partie B — Approche par héritage (`src/inheritance.hpp`, `src/inheritance.cpp`)

- `Distance_core` : classe abstraite avec `_value` protégé, constructeur
  protégé, méthode virtuelle pure `_print`, quatre méthodes virtuelles pures
  `convert_to_[UNIT]()` (une par unité), destructeur virtuel, et opérateur
  `<<` sur `Distance_core const*`.
- `Distance` : wrapper autour d'un `Distance_core const* _content`, exposant
  les mêmes méthodes de conversion et l'opérateur `<<`.
- Une classe fille par unité (`Distance_meters`, `Distance_feet`,
  `Distance_leagues`, `Distance_nautic_miles`), chacune avec constructeur,
  destructeur, `_print` et les conversions.
- Opérateurs de comparaison définis sur `Distance` (via une méthode
  `get_value` ajoutée à `Distance_core`).

## Exercice 2 — Gestion mémoire et états des données

### Partie A — Fuites mémoire (`src/memory_1.cpp` → `src/memory_3.cpp`)

1. **`memory_1.cpp`** : crée `d1` (1 mètre), `d2` (3 lieues), affiche leur
   comparaison, crée `d3` à partir de `nullptr`, l'affiche, retourne 0.
2. Compiler avec `-g -O0` et lancer sous `valgrind --leak-check=yes` :
   plusieurs erreurs attendues, dont une erreur de segmentation.
3. **`memory_2.cpp`** : copie de `Distance` renommée `Distance_1`, avec
   destructeur qui libère `_content` et constructeur par copie supprimé
   (`= delete`) pour éviter le double pointeur. Ne doit rester qu'une erreur
   sous `valgrind`.
4. **`memory_3.cpp`** : ajout d'un `assert` dans le constructeur pour refuser
   un pointeur `nullptr` (limite : ne protège pas contre un pointeur invalide
   non nul, cf. l'exemple avec `reinterpret_cast`).

### Partie B — Les 4 états d'une donnée (`src/data_1.*`, `src/data_2.*`)

1. **`data_1`** : quatre surcharges `void test(...)` pour `int`, `int*`,
   `int&`, `int&&`. Le compilateur signale une ambiguïté entre `int`, `int&`
   et `int&&`.
2. **`data_2`** : remplacement de la version `int` par `int const&&` pour
   lever l'ambiguïté (nécessite `std::as_const` + `std::move` pour être
   obtenu depuis une donnée non-const).

## Compilation

```bash
g++ -std=c++17 -g -O0 -Wall -Wextra -o memory_1 src/memory_1.cpp src/inheritance.cpp
```
(adapter les fichiers sources selon l'exercice compilé)

## Vérification mémoire

```bash
valgrind --leak-check=yes ./memory_1
valgrind --leak-check=yes ./memory_2
valgrind --leak-check=yes ./memory_3
```

## Notes importantes

- Les `enum` doivent être déclarées `enum class` (et non `enum` comme en C).
- Toute méthode nécessitant d'accéder aux membres privés/protégés d'une
  classe externe doit être déclarée `friend`.
- Une classe est abstraite dès qu'une de ses méthodes est déclarée `= 0`.
- Un destructeur de classe mère destinée à être héritée doit être `virtual`
  (implémentation vide `virtual ~C() {}` suffit dans la plupart des cas).
- Toute déclaration va dans un `.hpp`, toute implémentation dans un `.cpp`.