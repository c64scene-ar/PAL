PAL
============

Punga Aventura text adventure language for Commodore 64 (spanish).

### Punga Aventura Language (PAL)

- Compiler *palc* currently on development.
- Featuring *Punga* keywords (DONDE? DISE, KOSAS? LAGORRA?) and builtin actions for every item within a KOSAS? object. Pungas standard guaranteed.
- Easy to script, hard to miss.
- Doesn't support NTSC yet.

Here is an example of the PAL language:

```
DONDE? LIVING! {
  DISE {
    Estas en living. Al norte no sabes que hay, y arriba menos. 

    Hay una escalera.  Un viento gelido te trae un mal augurio.

    Cuidado, muchacho. Esto puede ser peligroso.

    Muy peligroso.
  }
  KOSAS? {
     "microondas" {
        DISE {
           Un microondas que no le importa a nadie
        }
     }
     "sofa" {
        DISE { Hay Un sofa reconfortante de cuero gastado.
              El unico en la casa. }
        mirar @ {
          DISE { El sofa parece confortable... }
        }
        agarrar @ {
          DISE { Agarrar el sofa? No no. Y donde lo pondrias? }
        }
        tirar del @ {
          DISE { Por mas fuerza que hagas, no podes tirar el sofa esto es muy loco.
          Empujarlo quizas? }
        }
        empujar @ {
          DISE { Intentas empujar el sofa pero no lo logras. }
        }
    }

    }

  LAGORRA? {
    norte { COCINA }
    arriba { TERRAZA }
    este { BANO }
  }

}

DONDE? BANO! {
  DISE {
    El banho tiene un extranho olor a humedad.
    No te gusta.
  }
  KOSAS? {
    "jabon" {
      DISE {
        Un jabon aroma al lavanda
      }
      usar @ {
        DISE { te lavas las manos ... }
      }
    }
    "shampoo" {
      DISE { Un shampoo de tocador especial }
      usar @ {
        DISE { no puedes usar un shampoo asi como asi, estas loco? }
      }
    }
  }
  LAGORRA? {
    oeste { LIVING }
  }
}

```


