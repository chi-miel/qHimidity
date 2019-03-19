# qHimidity
IOT School Project

Capteur d’humidité
Master RIE 2018 / 2019
Adrien FACCHIN, Adrien SIPASSEUTH, Florian SEGURA et Kilian ERRAES


## Scénario d’usage
                   
Notre IOT nommé qHumidity sera équipé d’un capteur d’humidité et de température.
Il sera placé dans la salle d’une usine industrielle nécessitant un environnement de travail ultra-maitrisé.
Cette salle doit avoir un taux d'humidité précis sous peine de détruire la matériel ou de rendre l'atmosphère de la salle toxique.
Les valeurs mesurées par qHumidity seront comparées à des seuils. Si les seuils sont dépassés, le capteur enverra un mail à l’exploitant et affichera un message d’alerte sur l’écran.
Le capteur d'humidité envoie des données qui permettent de piloter une machine de régulation automatique de l'humidité.
Ce capteur est primordial pour assurer la sécurité de l'activité de l'entreprise et des salariés.
Personne ne doit pouvoir falsifier ou bloquer les valeurs envoyées par le capteur.

## Composition de qHumidity              
* Une carte Arduino Uno
* Capteur d’humidité DHT11
* Capteur de luminosité
* Capteur de mouvement (de type Tilt dans le prototype, l’idéal serait un accéléromètre)
* Module WiFi (non mis en place dans le prototype)
* Un écran LCD pour afficher les valeurs
## Notion de sécurité

### Hardware

qHumidity peut être attaqué physiquement si on a accès au boitier.
Il est possible de modifier les valeurs mesurées par le capteur d’humidité/température et ainsi tromper les seuils.
Il peut se passer deux choses : la personne malveillante doit ouvrir le boitier et pour cela il doit le bouger.
Pour éviter une modification des éléments du boitier nous l’avons équipé de 2 capteurs de sécurité :

* un capteur de luminosité

Enfermé dans la boitier, ce capteur capte une valeur de luminosité très faible. Une fois le boitier ouvert cette valeur va fortement augmenter.

→ on détecte alors que le boîtier est ouvert et on affiche un message d’erreur sur l’écran + envoie de mail + éventuellement un arrêt de l’application.
Ce capteur peut être falsifié mais pour cela il faudra bouger le boîtier.

* un capteur de mouvement

Le boîtier est fixé en mur, si il en est décroché, le capteur va le détecter.
Le boîtier a été créé grâce à une découpe laser. Le gabarit à été créé sur le site : https://www.makercase.com/
Le design a été pensé pour contenir tous les éléments electroniques confiné entre eux. Toutes infractations à la boite générera une alerte.
C'est alors que l'on détecte que le boitier est en mouvement et on affiche un message d’erreur sur l’écran + envoie de mail + éventuellement un arrêt de l’application.
Dans le prototype on utilise un capteur “tilt” qui n’est pas très précis. L’idéal serait un accéléromètre.

Pour palier à toute attaque comme une coupure de courant ou une prise débrancher. Le produit final devra être équipé d’une pile et d’une alarme sonore.
Si le boitier n’est plus alimenté électriquement, la pile prend le relais et fait sonner l’alarme.

Puisque le capteur sera connecté au réseau, on pourra également “monitorer” le capteur avec des pings régulier. Si on ne ping plus le capteur, une alerte peut-être envoyé à l’exploitant via l’outil de monitoring.



