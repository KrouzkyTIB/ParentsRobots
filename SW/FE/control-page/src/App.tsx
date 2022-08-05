import React from 'react';
import './App.css';
import MovementHandler from "./Components/MovementHandler";
import LightsButton from "./Components/LightsButton"

function App() {
    return (
        <div className="App">
            <header className="App-header">
            </header>
            <LightsButton lightsChangeHandler={() => {
            }}/>
            <MovementHandler moveCallback={() => {
            }}/>
        </div>
    );
}

export default App;
