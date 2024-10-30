# Wavetable Component

The effects were completed by Gabriella Stickney.

The format of your score files: A .score file was used, in the XML format

##### The actual score file used for your selection: The actual score file used for your selection: [Wave.score](./Wave.score) is the score file used to demonstrate the effects component. This is the audio file generated from the .score file: [Wave.wav](./Wave.wav). AI was used to create this piece.


Synthesis Component(s):
- Wavetable Synthesizer: Wavetable synthesis uses short, single-cycle audio recordings to produce sound, with waveforms that can be derived from real instruments or created mathematically. Unlike longer samples, these waveforms are stored in a "wavetable" and modulated to create dynamic sounds. A core feature is the ability to sweep through different waveforms in the wavetable, modulated by an LFO, envelope, or pressure changes, which produces smooth, evolving timbres. Some wavetables emulate analog effects such as pulse-width modulation through variations in square wave duty cycles. 
- Envelope generation: Envelope generation controls how a sound evolves in stages: Attack is the initial rise from silence to peak volume, with faster attacks sounding sharp and slower ones more gradual. Decay follows, where the sound drops from peak to a steady Sustain level, which holds as long as the note is played. Finally, Release controls how the sound fades back to silence after the note ends. This ADSR model can shape not only volume but also other sound characteristics, allowing for dynamic, expressive tones.
- Pitch: Pitch adjustment in synthesis involves altering the playback speed of a waveform to change its frequency. For example, playing a waveform at double speed doubles the pitch, while playing it slower lowers the pitch. By modifying the sample rate, you can control the playback speed and, consequently, the pitch.
- Attack and sustain waves: In wavetable synthesis, attack and sustain are achieved with two waveforms: one for the attack phase and another that repeats during the sustain phase. The first waveform plays for the attack, and when it finishes, the second waveform loops to sustain the sound until it fades out or the note ends. This approach mimics the natural sound evolution of many acoustic instruments.
- Glissando: A glissando is a smooth, continuous transition between two pitches, creating a glide effect from one note to the next. This technique, common in various instruments, adds expressiveness by connecting notes seamlessly rather than jumping between them, allowing for fluid movement across pitches.


The grading elements supported are 
- Wave playback on demand from the sequencer
- Envelope generation
- Pitch
- Attack and sustain waves
- Glissando


A copy of the Wave.score file is below:

```xml
﻿<?xml version="1.0" encoding="utf-8"?>
<score bpm="120" beatspermeasure="4">
   <instrument instrument="wavetable">
       <note measure="1" beat="1" duration="0.5" note="G4" gliss="E4"/>
       <note measure="1" beat="1.5" duration="0.5" note="E4"/>
       <note measure="1" beat="2" duration="0.5" note="C4"/>
       <note measure="1" beat="2.5" duration="1" note="A3"/>
       <note measure="1" beat="4" duration="0.5" note="G4"/>
       <note measure="1" beat="4.5" duration="0.5" note="F3" gliss="C4"/>

       <note measure="2" beat="1" duration="0.5" note="B3"/>
       <note measure="2" beat="1.5" duration="0.5" note="D4"/>
       <note measure="2" beat="2" duration="0.5" note="G4"/>
       <note measure="2" beat="2.5" duration="1" note="A3" gliss="F3"/>
       <note measure="2" beat="4" duration="1" note="C4"/>

       <note measure="3" beat="1" duration="0.5" note="E4" gliss="C4"/>
       <note measure="3" beat="1.5" duration="0.5" note="D4"/>
       <note measure="3" beat="2" duration="0.5" note="A3"/>
       <note measure="3" beat="2.5" duration="0.5" note="C4"/>
       <note measure="3" beat="3" duration="0.5" note="B3" gliss="F3"/>
       <note measure="3" beat="4" duration="0.5" note="A3"/>

       <note measure="4" beat="1" duration="0.5" note="G4"/>
       <note measure="4" beat="1.5" duration="0.5" note="C4"/>
       <note measure="4" beat="2" duration="0.5" note="D4" gliss="A3"/>
       <note measure="4" beat="2.5" duration="0.5" note="F3"/>
       <note measure="4" beat="3" duration="1" note="G4"/>
       <note measure="4" beat="4" duration="1" note="B3"/>

       <note measure="5" beat="1" duration="0.5" note="A3"/>
       <note measure="5" beat="1.5" duration="0.5" note="E3" gliss="F3"/>
       <note measure="5" beat="2" duration="0.5" note="C4"/>
       <note measure="5" beat="2.5" duration="1" note="G3"/>
       <note measure="5" beat="4" duration="0.5" note="D3"/>

       <note measure="6" beat="1" duration="0.5" note="F3"/>
       <note measure="6" beat="1.5" duration="0.5" note="A3"/>
       <note measure="6" beat="2" duration="0.5" note="E3"/>
       <note measure="6" beat="2.5" duration="1" note="C4"/>
       <note measure="6" beat="4" duration="1" note="D4"/>

       <note measure="7" beat="1" duration="1" note="B3"/>
       <note measure="7" beat="2" duration="1" note="A3"/>
       <note measure="7" beat="3" duration="0.5" note="G3" gliss="E3"/>
       <note measure="7" beat="4" duration="0.5" note="C4"/>

       <note measure="8" beat="1" duration="0.5" note="F3"/>
       <note measure="8" beat="1.5" duration="0.5" note="A3"/>
       <note measure="8" beat="2" duration="0.5" note="D4" gliss="G3"/>
       <note measure="8" beat="2.5" duration="1" note="C4"/>
   </instrument>
</score>
```
