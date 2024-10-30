# Effects Component

The effects were completed by Bhaaniu Jain.

##### The format of your score files: A .score file was used, in the XML format

##### The actual score file used for your selection: [effects_test.score](./Project1/effects_test.score) is the score file used to demonstrate the effects component. This is the audio file generated from the .score file: [effects_test](./Project1/efffects_test.wav). AI was used to add some chords towards the end to create a longer piece.

Effects:

- Noisegate:
  Noise gates are common in audio recording and live sound environments. They help keep audio clean by preventing background sounds from entering the mix. They’re often used on individual instrument tracks, vocal recordings, and drum microphones to prevent bleed from other instruments or ambient noise.
- Compression:
  Compression is a dynamic audio processing technique that reduces the volume of the loudest parts of a sound while boosting softer parts, resulting in a more balanced and controlled sound.
- Chorus:
  Chorus is an audio effect that thickens and broadens a sound by creating multiple, slightly varied copies of the original signal and blending them. This simulates the effect of multiple instruments or voices playing or singing the same notes together.
- Flange:
  Flanging is an audio effect that creates a sweeping, jet-like sound by mixing two identical audio signals, with one signal slightly delayed. This slight delay causes phase cancellations and reinforcements in different frequency bands, producing a characteristic "whooshing" or "swirling" effect.


The grading elements supported are
- Component passes audio
- 1 Effect
- 3 Effects
- Controllable effects send
- 4 Effects


The XML for the effects_test.score is below:

```xml
﻿<?xml version="1.0" encoding="utf-8"?>
<score bpm="120" beatspermeasure="2">
     <instrument instrument="ToneInstrument" chorus="8" flange="8" noisegate="8" compression="8">
          <note measure="1" beat="2" duration="0.33" note="F4"/>
          <note measure="1" beat="2.33" duration="0.33" note="G4"/>
          <note measure="1" beat="2.6" duration="0.33" note="A4"/>

          <note measure="2" beat="1" duration="0.5" note="Bb4"/>
          <note measure="2" beat="1" duration="0.5" note="G4"/>
          <note measure="2" beat="1" duration="0.5" note="Eb4"/>

          <note measure="3" beat="1" duration="0.5" note="Bb4"/>
          <note measure="3" beat="1" duration="0.5" note="G4"/>
          <note measure="3" beat="1" duration="0.5" note="Eb4"/>

          <note measure="4" beat="1" duration="0.5" note="Bb4"/>
          <note measure="4" beat="1" duration="0.5" note="D4"/>
          <note measure="4" beat="1" duration="0.5" note="F4"/>

          <note measure="4" beat="2" duration="0.5" note="Bb4"/>
          <note measure="4" beat="2" duration="0.5" note="G4"/>
          <note measure="4" beat="2" duration="0.5" note="Eb4"/>

          <note measure="5" beat="1" duration="0.5" note="Bb4"/>
          <note measure="5" beat="1" duration="0.5" note="D4"/>
          <note measure="5" beat="1" duration="0.5" note="F4"/>

          <note measure="6" beat="1" duration="0.5" note="G4"/>
          <note measure="6" beat="1.5" duration="0.5" note="F#4"/>
          <note measure="6" beat="2" duration="0.5" note="G4"/>
          <note measure="6" beat="2.5" duration="0.5" note="G#4"/>

          <note measure="7" beat="1" duration="1" note="A4"/>
          <note measure="7" beat="2" duration="1" note="F4"/>

          <note measure="8" beat="1" duration="3" note="Bb4"/>
          <note measure="8" beat="1" duration="3" note="F4"/>
          <note measure="8" beat="1" duration="3" note="D4"/>

          <note measure="9" beat="1" duration="3" note="A4"/>
          <note measure="9" beat="2" duration="3" note="F4"/>

          <note measure="10" beat="1" duration="2" note="Bb4"/>
          <note measure="10" beat="1" duration="2" note="F4"/>
          <note measure="10" beat="1" duration="2" note="D4"/>


 	  <note measure="11" beat="1" duration="1" note="E4"/>
          <note measure="11" beat="1" duration="1" note="G4"/>
          <note measure="11" beat="2" duration="1" note="B4"/>

          <note measure="12" beat="1" duration="0.75" note="C5"/>
          <note measure="12" beat="1.75" duration="0.75" note="E5"/>
          <note measure="12" beat="2.5" duration="0.5" note="G5"/>

          <note measure="13" beat="1" duration="1.5" note="D4"/>
          <note measure="13" beat="1" duration="1.5" note="F4"/>
          <note measure="13" beat="2.5" duration="0.5" note="A4"/>

          <note measure="14" beat="1" duration="0.5" note="C4"/>
          <note measure="14" beat="1.5" duration="0.5" note="E4"/>
          <note measure="14" beat="2" duration="0.5" note="G4"/>
          <note measure="14" beat="2.5" duration="0.5" note="B4"/>
     </instrument>
     <instrument instrument="Chorus">
          <note delay=".0025" wet=".7" dry=".3" range=".5" rate="2"/>
     </instrument>
     <instrument instrument="Flange">
          <note delay=".0005" wet=".7" dry=".3" range=".5" rate="2" level="2"/>
     </instrument>
     <instrument instrument="NoiseGate">
          <note threshold="50" wet="1" dry="0"/>
     </instrument>
     <instrument instrument="Compressor">
          <note threshold="10" wet="1" dry="0" ratio="2"/>
     </instrument>
</score>
```
