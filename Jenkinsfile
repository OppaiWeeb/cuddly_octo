pipeline {
    agent none
    stages {
        stage('Check norme') {
            agent {docker 'alecromski/epitest:latest'}
            steps {
                sh 'uname -a'
                sh 'pwd '
                sh 'mkdir -p build && cd build && cmake .. && make'
                sh 'pwd '
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
