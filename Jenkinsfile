pipeline {
    agent none
    stages {
        stage('Check norme') {
            agent {docker 'alecromski/epitest:latest'}
            steps {
                sh 'git submodule update --init'
                sh 'make'
            }
        }

    }
    post {
        success {
            echo "success";
        }
        failure {
            echo "failure"
        }
    }
}
