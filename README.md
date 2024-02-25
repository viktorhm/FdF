<h1 align = center>FDF</h1>



<h2>introduction</h2>

Fdf, un projet conçu avec la minilibx 42 Paris. Le but de ce projet est de découvrir le monde de la 3D. Ce projet se divise en 3 parties :
	
- Partie obligatoire 
	 * Ouverture et lecture de la carte.
	 * Le fonctionnement de la minilibx et l'algorithme de tracé de segment de Bresenham.
	 * Affichage de la carte sur les écrans et création d'un effet de 3D
- Partie bonus :
	* Gestion de la caméra, zoom et axes.
	* Gestion de la couleur. sois par lecture de la carte sois un degrader.
	* Petit bonus : possibilité de baisser l'axe Z.



<h2>build and executing</h2>

- clone repo :
```
git clone git@github.com:viktorhm/FdF.git
cd Fdf
```
  
 -add submodule :
```
git submodule init 
git submodule update
```
 
-compilation :
```
make
```
 
-how work :
```
./fdf maps/42.fdf
```

<h2>commande</h2>

### direction
	> - `w`: up
	> - `s`: down
	> - `a`: right
	> - `d`: left
### rotation
	> - `{`: angle y+
	> - `}`: angle y-
	> - `>`: angle x+
	> - `<`: angle x-
### zoom
	> - `-`: -
	> - `+`: +
### level
	> - `q` :-
	> - `e` :+

