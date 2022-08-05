import React from 'react';
import './App.css';
import MovementHandler from "./classes/MovementHandler";

function App() {
    return (
        <div className="App">
            <header className="App-header">
            </header>
            <MovementHandler moveCallback={() => {
            }}/>
        </div>
    );
}

export default App;
