# 🧩 push_swap

**Projet 42 - Cursus 42 Lyon**  
Implémentation d’un algorithme de tri en C utilisant deux piles et un ensemble limité d’opérations.

---

## 🧠 Description

Le but du projet **push_swap** est d’écrire un programme capable de trier une pile d’entiers avec un nombre minimal d’opérations, en utilisant uniquement un ensemble d’instructions spécifiques (`sa`, `pb`, `ra`, etc.).  
L’objectif est d’optimiser la **complexité algorithmique** et la **gestion mémoire**, tout en respectant les contraintes du sujet.

---

## ⚙️ Fonctionnalités principales

- Manipulation de deux piles à l’aide d’opérations restreintes  
- Implémentation d’algorithmes de tri efficaces (ex : tri par insertion, tri rapide adapté)  
- Gestion des erreurs et des cas limites (données invalides, doublons, pile vide)  
- Calcul et comparaison du nombre de coups  
- Vérification automatique du résultat via le programme `checker`

---

## 🧠 Compétences développées

- Algorithmie et analyse de la complexité  
- Gestion de la mémoire et optimisation en C  
- Manipulation de structures de données (piles / listes chaînées)  
- Gestion d’erreurs et robustesse du code  
- Conception et mise en œuvre d’algorithmes performants  

---

## ⚙️ Compilation

Utilisez le **Makefile** fourni :
```bash
make
```

Cela génère deux exécutables :
- `push_swap` : génère la suite d’opérations pour trier la pile  
- `checker` : vérifie la validité des opérations

---

## 🚀 Exemple d’exécution

```bash
./push_swap 2 1 3 6 5 8
```

Sortie :
```
pb
pb
sa
pa
pa
```

---

## 🖼️ Aperçu visuel
![pushSwapVisualizer](https://github.com/user-attachments/assets/428f9e10-7821-41eb-aac9-6eab892c684d)

