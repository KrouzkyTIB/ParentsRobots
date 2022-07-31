import React from 'react';
import './App.css';
import './SpeedSlider/Slider.css'
import Slider, {Position} from "./SpeedSlider/Slider";

function App() {
    return (
        <div className="App">
            <header className="App-header">
            </header>
            <Slider refreshCallback={(value: number) => console.log("left" + value)} position={Position.LEFT}/>
            <Slider refreshCallback={(value: number) => console.log("right" + value)} position={Position.RIGHT}/>
        </div>
    );
}

export default App;
