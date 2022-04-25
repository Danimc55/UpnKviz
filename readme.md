# UPN Kviz
Kviz: Imamo 3 tipke A, B in C. Krmiljenje naj ugotavlja, katera tipka je bila pritisnjena prva, katera druga in katera tretja. Zelena LED pomeni, da ni nihče še pritisnil na tipko (začetek kviza), rumena LED pomeni, da je vsaj en igralec pritisnil na tipko. Ko so vsi trije igralci pritisnili svoje tipke, utripa rdeča LED. S tipko za reset R ugasnemo rdečo LED diodo in resetiramo kviz. Za prikaz vrstnega reda uporabite LCD zaslon.

## Demonstracija
https://user-images.githubusercontent.com/29386047/164197462-67516048-ddc1-4c33-a572-b0aaeed73b1d.mp4

## Avtorji
* Danijel Tomić
* Žan Hribar

## Kosovnica

* 4x tipke
* 4x 1kΩ upor
* 1x trimmer
* 1x lcd
* 3x led dioda (1x Zelena, 1x rdeča, 1x rumena)
* 3x 220Ω upor

## Priredbeni seznam

### Vhodi
| Oznaka v načrtu | Naslov operanda | Vrsta kontaknta | Pomen                          |
|-----------------|-----------------|-----------------|--------------------------------|
| A               | X0              | N.C.            | Gumb za igralca 1.             |
| B               | X1              | N.C.            | Gumb za igralca 2.             |
| C               | X2              | N.C.            | Gumb za igralca 3.             |
| R               | X3              | N.C.            | Gumb za resetiranje kviza.     |
| TRIMER          |                 |                 | Nastavljanje kontrasta za LCD. |


## Breadboard vezava
![Breadboard vezava za upn kviz](/img/schematic.png "Breadboard vezava")

## Shema
![Shema vezave za upn kviz](/img/schema.png "Shema")



