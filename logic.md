# Programming Logic

> For each behaviour, create the mermaid flowchart. Start each flowchart with a Heading naming the functionality. Delete this comment prior to submission.

## Logic 1

```mermaid
flowchart TD
    Start([Doorbell])
    GetButtonStatus(Get Button Status)
    CheckButton{has button been pressed}
    SoundDoorBell(play Sound)
    finish([end])

    Start-->GetButtonStatus-->CheckButton
    CheckButton-->|Yes| SoundDoorBell
    CheckButton-->|No| finish
    SoundDoorBell-->finish    
```
## Logic 2
```mermaid
flowchart TD
    Start([Doorbell])
    GetButtonStatus(Get Button Status)
    CheckButton{has button been pressed}
    SoundDoorBell(play Sound)
    finish([end])

    Start-->GetButtonStatus-->CheckButton
    CheckButton-->|Yes| SoundDoorBell
    CheckButton-->|No| finish
    SoundDoorBell-->finish    
```
##   Logic 3
```mermaid
flowchart TD
    Start([SD card]) -->
    Log(info to card) -->
    Info(Once logged cry) 
```


## Logic 4
```mermaid
flowchart TD
    Start(cry) -->
    Cry(cry harder) -->
    Weep(start weeping)
```

## Logic 5
```mermaid 
flowchart TD
    Start(PIR) -->
    check(Infared) -->
    if(spam piezo)
    
