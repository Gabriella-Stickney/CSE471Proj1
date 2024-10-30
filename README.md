# Project 1: Wavetable Synthesizer with Effects Component

The .score file we used to generate this audio to showcase the wavetable synthesizer and the effects components is called "furelise.score".

[Link to Audio File](./Project1/fureelise.wav)

[Link to Score File](./Project1/furelise.score)
__________________________________________________________________________________________________________________________________

## The group members:
* Gabriella Stickney
* Bhaaniu Jain


## Navigation:
* [Effects](./Project1/Components/Effects.md)
* [Wavetable](./Project1/Components/WaveTable.md)


## Project Details:
In this project we were tasked with creating an Effects Component along with a synthesizer of our choice. We utilized multiple XML Files to store the notes and information about which effects and synthesizer we wanted to use. Each note is tied to an instrument which is specified at the top along with the the effect(s) implemented within the score file as well. We can also have multiple effects running at the same time.
Here is a sample base XML file using the "fight2.score" file which was provided to us to use with step 5:
```xml
<?xml version="1.0" encoding="utf-8"?>
<score bpm="120" beatspermeasure="2">
     <instrument instrument="ToneInstrument">
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
     </instrument>
</score>
```

