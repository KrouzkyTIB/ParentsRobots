import React, {Component} from 'react';
import './App.css';
import MovementHandler from "./Components/MovementHandler";
import LightsButton from "./Components/LightsButton"
import ConnectionStatus from "./Components/ConnectionStatus";
import ConnectionManager from "./Connection/ConnectionManager";






class App extends Component<any, any> {
    render() {
        const connectionManager = new ConnectionManager();


        return (
            <div className="App">
                <header className="App-header">
                </header>
                <LightsButton lightsChangeHandler={connectionManager.refreshLightsStatus}/>
                <ConnectionStatus connected={true}/>
                <MovementHandler moveCallback={connectionManager.refreshPowerSettings}/>
            </div>
        );
    }

}

export default App;
