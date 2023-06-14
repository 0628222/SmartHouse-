# Programming Logic

> For each behaviour, create the mermaid flowchart. Start each flowchart with a Heading naming the functionality. Delete this comment prior to submission.

## Doorbell

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
## Door locker
```mermaid
flowchart TD
    Start([Doorlocker])
    GetSonarDistance(Get Distance)
    CheckSonarDistance(check Distance)
    closeAndLockDoor(Close and Lock Front Door)
    KeepDoorOpen(doorOpen)
    finish([end])

    Start-->GetSonarDistance-->checkSonarDistance
    CheckSonarDistance-->|Yes| closeAndLockDoor
    checkSonarDistance-->|No| keepDoorOpen
    closeAndLockDoor--> finish    
```
##   Logic 3
```mermaid
flowchart TD
    Start([SD card]) -->
    Log(info to card) -->
    Info 
```


## Logic 4
```mermaid
flowchart TD
   start([PIR])
    Start(PIR) -->
    Checking(check for Infared) -->
    Infared(alarm)-->|yes| flash lights on 
```

## Logic 5
```mermaid 
flowchart TD
    Start([PIR])
    GetPIRStatus(Get PIR Status)
    CheckPIR{Has Infared been detected}
    SoundAlarm(Turn Lights On)
    finish([end])
    
    Start-->GetPIRstatus-->CheckPIR
    CheckPIR-->|Yes| SoundAlarm
    CheckPIR-->|No| finish
    SoundAlarm-->finish    
