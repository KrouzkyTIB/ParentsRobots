import {Component} from "react";

type ConnectionStatusData = {
    connected: boolean
}


class ConnectionStatus extends Component<ConnectionStatusData, {}> {

    private handleCssClass() {
        return this.props.connected ? "connected" : "disconnected"
    };

    private handleText() {
        return this.props.connected ? "Connected" : "Disconnected";
    }


    render() {
        return (
            <div className={"connection-status " + this.handleCssClass()}>
                {this.handleText()}
            </div>
        );
    }

}

export default ConnectionStatus;