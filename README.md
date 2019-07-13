

```
find -name positions | while read line; do mv $line $line.coord; mv $line.orig $line; done
find -name positions | while read line; do sed -i -e 's=^\(.*object.*\)positions.orig;=\1positions;=' $line; done
```

```
find -name positions | while read line; do mv $line $line.orig; mv $line.coord $line; done
```
