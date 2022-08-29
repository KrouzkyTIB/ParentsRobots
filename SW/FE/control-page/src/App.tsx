import React, {Component} from 'react';
import './App.css';
import MovementHandler from "./Components/MovementHandler";
import LightsButton from "./Components/LightsButton"
import ConnectionManager from "./Connection/ConnectionManager";

type ApplicationState = {
    connectionManager: ConnectionManager
    connected: boolean
    _intervalID: NodeJS.Timer | null
}


class App extends Component<{}, ApplicationState> {

    constructor(props: {}) {
        super(props)
        this.state = {
            connected: true,
            connectionManager: ConnectionManager.getInstance(),
            _intervalID: null
        }
    }

    render() {
        return (
            <div className="App">
                <header className="App-header">
                </header>
                <LightsButton lightsChangeHandler={(lightsOn: boolean) => {
                    this.state.connectionManager.lightsOn = lightsOn
                }}/>
                <MovementHandler moveCallback={this.state.connectionManager.refreshPowerSettings.bind(this.state.connectionManager)}/>
            </div>
        );
    }

}

export default App;
